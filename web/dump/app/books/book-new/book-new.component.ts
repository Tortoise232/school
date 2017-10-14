import {Component, Input} from "@angular/core";
import {Location} from '@angular/common';

import {Book} from "../shared/book.model";
import {BookService} from "../shared/book.service";


@Component({
    moduleId: module.id,
    selector: 'ubb-book-new',
    templateUrl: './book-new.component.html',
    styleUrls: ['./book-new.component.css'],
})
export class BookNewComponent {
    @Input() book: Book;

    constructor(private bookService: BookService,
                private location: Location){
    }

    goBack(): void {
        this.location.back();
    }

    saveAttempt = false;

    initSave(){
        this.saveAttempt = true;
    }

    save(title, author, genre, price): void {
        console.log("save book: ", title, author, genre, price);
        this.bookService.create(title, author, genre, price)
            .subscribe(_ => this.goBack());
    }
}