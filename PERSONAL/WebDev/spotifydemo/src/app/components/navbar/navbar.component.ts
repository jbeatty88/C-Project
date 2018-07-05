import { Component } from '@angular/core';
declare var module: {
    id: string;
  }

@Component({
  moduleId:module.id,  
  selector: 'navbar',
  templateUrl: 'navbar.component.html',
//   styleUrls: ['./app.component.css']
})
export class NavbarComponent {
  title = 'app';
}
