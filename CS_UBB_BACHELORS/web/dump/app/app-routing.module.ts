import { NgModule }             from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import {BookDetailComponent} from "./books/book-detail/book-detail.component";
import {BooksComponent} from "./books/books.component";
import {BookNewComponent} from "./books/book-new/book-new.component";
import {ClientDetailComponent} from "./clients/client-detail/client-detail.component";
import {ClientsComponent} from "./clients/clients.component";
import {ClientNewComponent} from "./clients/client-new/client-new.component";
import {BuyBooksComponent} from "./buy-book/buy-books.component";
import {ShoppingCartComponent} from "./shopping-cart/shopping-cart.component";

const routes: Routes = [
    // { path: '', redirectTo: '/home', pathMatch: 'full' },
    { path: 'books',     component: BooksComponent },
    { path: 'book/detail/:id', component: BookDetailComponent},
    { path: 'book/new', component: BookNewComponent},

    { path: 'clients',     component: ClientsComponent },
    { path: 'client/detail/:id', component: ClientDetailComponent},
    { path: 'client/new', component: ClientNewComponent},

    { path: 'buy-books', component: BuyBooksComponent},
    { path: 'shopping-cart', component: ShoppingCartComponent}
];
@NgModule({
    imports: [ RouterModule.forRoot(routes) ],
    exports: [ RouterModule ]
})
export class AppRoutingModule {}
