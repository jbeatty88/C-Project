import { Component } from '@angular/core';
// import { HTTP_PROVIDERS } from '@angular/http';
import { HttpModule } from '@angular/http';

declare var module: {
  id: string;
}
import { NavbarComponent } from './components/navbar/navbar.component';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  providers: [HttpModule]
  // styleUrls: ['./app.component.css'],
})
export class AppComponent {
  title = 'app';
}
