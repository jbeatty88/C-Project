/*
  TOKENTYPES:
  COMMA: ,
  PERIOD .
  Q_MARK ?
  LEFT_PAREN (
  RIGHT_PAREN )
  COLON :
  COLON_DASH :-
  MULTIPLY *
  ADD +
  SCHEMES "Schemes"
  FACTS "Facts"
  RULES "Rules"
  QUERIES "Queries"
  ID - Letter followed by 0 or more digits
  STRING - Any seq of chars in single quotes
  COMMENT - A block comment with #| |#
  WHITESPACE - Any char recognized by the isspace()
  UNDEFINED - Any char not tokenized
  EOF - End of input file
*/

enum token {
  COMMA_TOKEN            = ",",
  PERIOD_TOKEN           = ".",
  Q_MARK_TOKEN           = "?",
  LEFT_PAREN_TOKEN       = "(",
  RIGHT_PAREN_TOKEN      = ")",
  COLON_TOKEN            = ":",
  COLON_DASH_TOKEN       = ":-",
  MULTIPLY_TOKEN         = "*",
  ADD_TOKEN              = "+",
  SCHEMES_TOKEN          = "Schemes",
  FACTS_TOKEN            = "Facts",
  RULES_TOKEN            = "Rules",
  QUERIES_TOKEN          = "Queries"
};
