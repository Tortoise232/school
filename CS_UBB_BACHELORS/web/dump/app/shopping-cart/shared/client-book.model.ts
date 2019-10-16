/**
 * Created by Laura on 5/6/2017.
 */
export class ClientBook{
    clientId: number;
    bookId: number;
    bookTitle: string;
    quantity: number;

    constructor(clientId: number, bookId: number, bookTitle: string, quantity: number) {
        this.clientId = clientId;
        this.bookId = bookId;
        this.bookTitle = bookTitle;
        this.quantity = quantity;
    }
}