import { Component } from '@angular/core';
declare var module: {
    id: string;
  }

@Component({
  moduleId:module.id,  
  selector: 'about',
  templateUrl: 'about.component.html',
//   styleUrls: ['./app.component.css']
})
export class AboutComponent {
  title = 'app';
}
