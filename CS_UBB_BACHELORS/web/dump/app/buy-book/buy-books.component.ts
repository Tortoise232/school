/**
 * Created by Laura on 5/6/2017.
 */
import {Component} from "@angular/core";
import {Location} from "@angular/common";

import {Book} from "../books/shared/book.model";
import {BookService} from "../books/shared/book.service";
import {Client} from "../clients/shared/client.model";
import {ClientService} from "../clients/shared/client.service";

@Component({
    moduleId: module.id,
    selector: 'ubb-buy-book',
    templateUrl: './buy-books.component.html',
    styleUrls: ['./buy-books.component.css'],
})
export class BuyBooksComponent {
    errorMessage: string;
    selectedClient: Client;
    showBooks: boolean;
    selectedBooks: Book[];
    availableBooks: Book[];

    constructor(private clientService: ClientService,
                private bookService: BookService,
                private location: Location) {
    }

    goBack(): void {
        this.location.back();
    }

    saveAttempt = false;

    initSave(){
        this.saveAttempt = true;
    }

    loadBooks(email: string) {
        this.showBooks = false;
        this.loadAvailableBooks();
        this.loadSelectedBooks(email);
    }

    noClientWithThatMail;

    private loadSelectedBooks(email: string) {
        this.clientService.getClients()
            .subscribe(
                clients => {
                    const currentClient = clients.filter(c => c.email === email);
                    //TODO there should be exactly one client in currentClient or err; handle errs
                    if(currentClient.length === 0){
                        this.noClientWithThatMail = true;
                    }
                    if (currentClient.length === 1) {
                        this.noClientWithThatMail = false;
                        this.selectedClient = currentClient[0];
                        this.showBooks = true;
                        this.loadSelectedBooksForClient(this.selectedClient);
                    }
                },
                error => this.errorMessage = <any>error);
    }

    private loadSelectedBooksForClient(client: Client) {
        this.selectedBooks = new Array();
        const bookIds = client.books;
        if (bookIds) {
            bookIds.forEach(id => {
                this.bookService.getBook(id)
                    .subscribe(
                        book => {
                            this.selectedBooks = this.selectedBooks
                                .concat([book]);
                        },
                        error => this.errorMessage = error);
            });
        }
    }

    private loadAvailableBooks() {
        this.bookService.getBooks()
            .subscribe(
                books => this.availableBooks = books,
                error => this.errorMessage = <any>error);
    }

    selectBook(book: Book) {
        const bk = this.selectedBooks.filter(b => b === book);
        if (bk.length > 0) {
            console.log("Book already selected!");
            alert("Book already selected!");
            return;
        }
        this.selectedBooks = this.selectedBooks.concat([book]);
    }

    removeSelectedBook(book: Book) {
        this.selectedBooks = this.selectedBooks.filter(b => b !== book);
    }

    save() {
        this.selectedClient.books = this.selectedBooks.map(b => b.id);
        console.log("Save ", this.selectedBooks, this.selectedClient.books);
        this.clientService.update(this.selectedClient)
            .subscribe(_ => this.goBack())
    }
}
