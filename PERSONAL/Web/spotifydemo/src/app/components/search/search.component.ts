import { Component } from '@angular/core';
import { SpotifyService } from '../../services/spotify.services'

declare var module: {
    id: string;
  }

@Component({
  moduleId:module.id,  
  selector: 'search',
  templateUrl: 'search.component.html',
  providers: [SpotifyService]
//   styleUrls: ['./app.component.css']
})
export class SearchComponent {
  searchStr:string; 

  constructor(private _spotifyService:SpotifyService){

  }

  searchMusic() {
    this._spotifyService.searchMusic(this.searchStr)
      .subscribe(res => {
        console.log(res.artists.items)
      })
  }
}
