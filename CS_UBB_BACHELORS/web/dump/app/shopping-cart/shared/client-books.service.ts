/**
 * Created by Laura on 5/6/2017.
 */
import {Injectable} from "@angular/core";
import {Headers, Http, Response} from "@angular/http";
import {ClientBook} from "./client-book.model";

import {Observable} from "rxjs";

@Injectable()
export class ClientBookService {
    private clientBookUrl = 'http://localhost:8080/api/shopping-cart';
    private headers = new Headers({'Content-Type': 'application/json'});

    constructor(private http: Http) {
    }

    getClientBooks(clientID: number): Observable<ClientBook[]> {
        return this.http.get(`${this.clientBookUrl}/${clientID}`, this.headers)
            .map(this.extractData)
            .catch(this.handleError);
    }

    private extractData(res: Response) {
        let body = res.json();
        return body.clientBooks || {};
    }

    private handleError(error: Response | any) {
        let errMsg: string;
        if (error instanceof Response) {
            const body = error.json() || '';
            const err = body.error || JSON.stringify(body);
            errMsg = `${error.status} - ${error.statusText || ''} ${err}`;
        } else {
            errMsg = error.message ? error.message : error.toString();
        }
        console.error(errMsg);
        return Observable.throw(errMsg);
    }

    saveItems(clientId: number, bookIdsItems: Object): Observable<ClientBook[]> {
        const url = `${this.clientBookUrl}/${clientId}`;
        let clientBooks = this.createClientBooks(clientId, bookIdsItems);
        console.log("items: ", clientBooks);
        console.log("request: ",JSON.stringify({"clientBooks": clientBooks}));
        return this.http
            .put(url, JSON.stringify({"clientBooks": clientBooks}), {headers: this.headers})
            .map(this.extractData)
            .catch(this.handleError);
    }

    private createClientBooks(clientId: number, bookIdsItems: Object): ClientBook[] {
        const arr: ClientBook[] = [];
        Object.keys(bookIdsItems).forEach(bookId => {
            const cb = new ClientBook(
                clientId,
                parseInt(bookId),
                null,
                bookIdsItems[bookId]);
            arr.push(cb);
        });
        return arr;
    }
}