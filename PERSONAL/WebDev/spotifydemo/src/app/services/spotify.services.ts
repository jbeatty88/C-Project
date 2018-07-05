import { Injectable } from '@angular/core';
import { Http, Headers } from '@angular/http';
import { map } from 'rxjs/operators';
// import { Http ,HttpModule} from '@angular/http' 

@Injectable()

export class SpotifyService{
    private searchUrl: string;

    constructor(private _http:Http){
        
    }

    searchMusic(str:string, type='artist'){
        this.searchUrl = 'https://api.spotify.com/v1/search?query='+str+'&offset=0&limit=20&type='+type
        return this._http.get(this.searchUrl)
            .pipe(map(res => res.json()));
    }
}