import {BrowserModule} from '@angular/platform-browser';
import {NgModule} from '@angular/core';
import {FormsModule} from '@angular/forms';
import {HttpModule} from '@angular/http';

import {AppComponent} from './app.component';
import {BookService} from "./books/shared/book.service";
import {AppRoutingModule} from "./app-routing.module";
import {BookDetailComponent} from "./books/book-detail/book-detail.component";
import {BooksComponent} from "./books/books.component";
import {BookListComponent} from "./books/book-list/book-list.component";
import {BookNewComponent} from "./books/book-new/book-new.component";
import {ClientService} from "./clients/shared/client.service";
import {ClientDetailComponent} from "./clients/client-detail/client-detail.component";
import {ClientsComponent} from "./clients/clients.component";
import {ClientListComponent} from "./clients/client-list/client-list.component";
import {ClientNewComponent} from "./clients/client-new/client-new.component";
import {BuyBooksComponent} from "./buy-book/buy-books.component";
import {ShoppingCartComponent} from "./shopping-cart/shopping-cart.component";
import {ClientBookService} from "./shopping-cart/shared/client-books.service";

@NgModule({
    declarations: [
        AppComponent,
        BookDetailComponent,
        BooksComponent,
        BookListComponent,
        BookNewComponent,

        ClientDetailComponent,
        ClientsComponent,
        ClientListComponent,
        ClientNewComponent,

        BuyBooksComponent,
        ShoppingCartComponent
    ],
    imports: [
        BrowserModule,
        FormsModule,
        HttpModule,
        AppRoutingModule
    ],
    providers: [BookService,ClientService, ClientBookService],
    bootstrap: [AppComponent]
})
export class AppModule {
}


