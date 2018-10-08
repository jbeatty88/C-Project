public class DatalogProgram {
    private Schemes schemes;
    private Facts facts;
    private Rules rules;
    private Queries queries;
    
    public DatalogProgram(Lex lex) {
        schemes = new Schemes(lex);
        facts = new Facts(lex);
        rules = new Rules(lex); 
        queries = new Queries(lex);
    }
}

public class Schemes {
    private List<Scheme> listOfSchemes;
    
    public Schemes(Lex lex){
        Utilities.checkFor(lex, TokenType.SCHEMES);
        Utilities.checkFor(lex, TokenType.COLON);

        listOfSchemes = new ArrayList<Scheme>();
        do {
            listOfSchemes.add(new Scheme(lex)); 
        } while(lex.getCurrentToken().getTokenType()  == TokenType.ID);
    }
}

public class Facts {
    private List<Fact> factList;
    
    public Facts(Lex lex){        
        Utilities.checkFor(lex,TokenType.FACTS); 
        Utilities.checkFor(lex,TokenType.COLON); 

        factList = new ArrayList<Fact>();
        while(lex.getCurrentToken().getTokenType() == TokenType.ID) {
            factList.add(new Fact(lex));
        }
    }
}

public class Rules {
    private List<Rule> rules;

    public Rules(Lex lex) {
        Utilities.checkFor(lex,TokenType.RULES); 
        Utilities.checkFor(lex,TokenType.COLON);
        rules = new ArrayList<Rule>();
        while(lex.getCurrentToken().getTokenType() == TokenType.ID) {
            rules.add(new Rule(lex));
        }
    }
}

public class Queries {
    private List<Query> queries;
    
    public Queries(Lex lex) {
        Utilities.checkFor(lex,TokenType.QUERIES);
        Utilities.checkFor(lex,TokenType.COLON);

        queries = new ArrayList<Query>();
        do {
            queries.add(new Query(lex));
        } while (lex.getCurrentToken().getTokenType() != TokenType.ID);
    }
}

public class Scheme {
    private Id id;
    private List<Id> ids;
    
    public Scheme(Lex lex){
        id = new Id(lex);
        Utilities.checkFor(lex, TokenType.LEFT_PAREN);
        
        ids = new ArrayList<Id>();
        while(true) {
            ids.add(new Id(lex));
        if (lex.getCurrentToken().getTokenType() != TokenType.COMMA) break;
            lex.advance();
        }
        
        Utilities.checkFor(lex, TokenType.RIGHT_PAREN);
    }
}

public class Fact {
    private Id id;
    private List<DLString> listOfStrings;
    
    public Fact(Lex lex){
        id = new Id(lex);
        Utilities.checkFor(lex, TokenType.LEFT_PAREN);
        
        listOfStrings = new ArrayList<DLString>();
        while(true) {
            listOfStrings.add(new DLString(lex));
        if(lex.getCurrentToken().getTokenType() != TokenType.COMMA) break;
            lex.advance();
        }
        
        Utilities.checkFor(lex, TokenType.RIGHT_PAREN);
        Utilities.checkFor(lex, TokenType.PERIOD);
    }
}

public class Rule {
    private HeadPredicate headPredicate;
    private List<Predicate> predicateList;
    
    public Rule(Lex lex) {
        headPredicate = new HeadPredicate(lex);
        Utilities.checkFor(lex, TokenType.COLON_DASH);
        
        predicateList = new ArrayList<Predicate>();
        while(true) {
            predicateList.add(new Predicate(lex));
        if(lex.getCurrentToken().getTokenType() != TokenType.COMMA) break;
            lex.advance();
        }

        Utilities.checkFor(lex, TokenType.PERIOD);
    }
}

public class Query
    extends Predicate
{
    public Query(Lex lex) {
        super(lex);
        Utilities.checkFor(lex, TokenType.Q_MARK);
    }
}

public class HeadPredicate {
    private Id id;
    private List<Id> ids;
    
    public HeadPredicate(Lex lex) {
        id = new Id(lex);
        Utilities.checkFor(lex, TokenType.LEFT_PAREN);
        
        ids = new ArrayList<Id>();
        while(true) {
            ids.add(new Id(lex));
        if(lex.getCurrentToken().getTokenType() != TokenType.COMMA) break;
            lex.advance();
        }
        
        Utilities.checkFor(lex, TokenType.RIGHT_PAREN);
    }
}

public class Predicate {
    private Id id;
    private List<Parameter> parameters;
    
    public Predicate(Lex lex) {
        id = new Id(lex);
        Utilities.checkFor(lex, TokenType.LEFT_PAREN);
        
        while(true) {
            parameters.add(Parameter.createParameter(lex));
        if(lex.getCurrentToken().getTokenType() != TokenType.COMMA) break;
            lex.advance();
        }        

        Utilities.checkFor(lex, TokenType.RIGHT_PAREN);
    }
}

public abstract class Parameter {
    private static final Set<TokenType> FIRST_OF_PARAMETER;
    
    public static boolean isInFirstOf(Lex lex) {
        return FIRST_OF_PARAMETER.contains(
            lex.getCurrentToken().getTokenType());
    }
    
    public static Parameter createParameter(Lex lex) {
        Parameter result = null;
        switch(lex.getCurrentToken().getTokenType()) {
        case ID:
            result = new Id(lex);
            break;
        case STRING:
            result = new DLString(lex);
            break;
        case LEFT_PAREN:
            result = new Expression(lex);
            break;
        default:
            throw new RuntimeException(
                "Looking for a Parameter but found " + lex.getCurrentToken());
        }
        
        return result;
    }
    
    public Parameter() {}
    
    static {
        Set<TokenType> temporarySet = new HashSet<TokenType>();
        temporarySet.add(TokenType.ID);
        temporarySet.add(TokenType.STRING);
        temporarySet.add(TokenType.LEFT_PAREN);
        FIRST_OF_PARAMETER = Collections.unmodifiableSet(temporarySet);
    }

}


public class Id 
    extends Parameter
{
    private String id;
    
    public Id(Lex lex) {
        Utilities.checkType(lex, TokenType.ID);
        id = lex.getCurrentToken().getValue();
        lex.advance();
    }
}

public class DLString
    extends Parameter
{
    private String constant;
    
    public DLString(Lex lex) {
        Utilities.checkType(lex, TokenType.STRING);
        constant = lex.getCurrentToken().getValue();
        lex.advance();
    }
}

public class Expression 
    extends Parameter
{
        Utilities.checkFor(lex, TokenType.LEFT_PAREN);
    private Parameter leftParameter;
    private Operator operator;
    private Parameter rightParameter;
    
    public Expression(Lex lex) {
        Utilities.checkFor(lex, TokenType.LEFT_PAREN);

        leftParameter = Parameter.createParameter(lex);
        operator = new Operator(lex);
        rightParameter = Parameter.createParameter(lex);
        
        Utilities.checkFor(lex, TokenType.RIGHT_PAREN);
    }
}

public class Operator {
    private TokenType operator;
    
    public Operator(Lex lex) {
        switch(lex.getCurrentToken().getTokenType()) {
            case ADD:
                operator = TokenType.ADD;
                break;
            case MULTIPLY:
                operator = TokenType.MULTIPLY;
                break;
            default:
                throw new RuntimeException(
                    "Expecting operator but found " + lex.getCurrentToken());
        }
        lex.advance();
    }

}


public class Utilities {
    public static void checkFor(Lex lex, TokenType tokenType) {
        checkType(lex, tokenType);
        advance();
    }

    public static void checkType(Lex lex, TokenType tokenType) {
        if(lex.getCurrentToken().getTokenType() != tokenType) {
            throw new RuntimeException(
                "Expecting token of type " + tokenType + " but found " +
                lex.getCurrentToken());
        }
    }
}