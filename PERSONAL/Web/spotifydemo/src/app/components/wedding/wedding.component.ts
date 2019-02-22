import { Component } from '@angular/core';
declare var module: {
    id: string;
  }

@Component({
  moduleId:module.id,  
  selector: 'wedding',
  templateUrl: 'wedding.component.html',
//   styleUrls: ['./app.component.css']
})
export class WeddingComponent {
  title = 'app';
}
