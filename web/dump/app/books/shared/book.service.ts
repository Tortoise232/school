import {Injectable} from '@angular/core';
import {Http, Response, Headers} from "@angular/http";

import {Book} from "./book.model";

import {Observable} from "rxjs";
import 'rxjs/add/operator/catch';
import 'rxjs/add/operator/map';


@Injectable()
export class BookService {
    private booksUrl = 'http://localhost:8080/api/books';
    private headers = new Headers({'Content-Type': 'application/json'});

    constructor(private http: Http) {
    }

    private extractData(res: Response) {
        let body = res.json();
        return body.books || {};
    }

    private extractBookData(res: Response) {
        let body = res.json();
        return body.book || {};
    }

    handle(error: Response|any){
        let message = error.text();
        alert("Error " + message);
        return Observable.throw(message);
    }

    getBooks(): Observable<Book[]> {
        return this.http.get(this.booksUrl)
            .map(this.extractData)
            .catch(this.handle);
    }

    getBook(id: number): Observable<Book> {
        return this.getBooks()
            .map(books => books.find(book => book.id === id));
    }

    create(title: string, author: string, genre:string, price:number): Observable<Response> {
        let book = {title, author, genre, price};
        return this.http
            .post(this.booksUrl, JSON.stringify({"book": book}), {headers: this.headers})
            .catch(this.handle);
    }

    update(book): Observable<Response> {
        const url = `${this.booksUrl}/${book.id}`;
        return this.http
            .put(url, JSON.stringify({"book": book}), {headers: this.headers})
            .catch(this.handle);
    }

    delete(id: number): Observable<void> {
        const url = `${this.booksUrl}/${id}`;
        return this.http
            .delete(url, {headers: this.headers})
            .map(() => null)
            .catch(this.handle);
    }
}
