/**
 * Created by Laura on 5/6/2017.
 */
import {Component} from '@angular/core';
import {Location} from "@angular/common";
import {ClientBook} from "./shared/client-book.model";
import {Client} from "../clients/shared/client.model";
import {ClientService} from "../clients/shared/client.service";
import {ClientBookService} from "./shared/client-books.service";

@Component({
    moduleId: module.id,
    selector: 'ubb-grades',
    templateUrl: './shopping-cart.component.html',
    styleUrls: ['./shopping-cart.component.css'],
})
export class ShoppingCartComponent {
    errorMessage: string;
    showItems: boolean;
    clientBooks: ClientBook[];
    selectedClient: Client;

    constructor(private clientService: ClientService,
                private clientBookService: ClientBookService,
                private location: Location) {

    }

    loadItems(email: string) {
        this.showItems = false;
        this.loadClientBooks(email);
    }

    saveAttempt = false;

    initSave(){
        this.saveAttempt = true;
    }

    noClientWithThatMail;

    private loadClientBooks(email: string) {
        this.clientService.getClients()
            .subscribe(
                clients => {
                    const clientArr = clients.filter(c => c.email === email);
                    //TODO handle errors (clientArr should contain one client)
                    if(clientArr.length === 0){
                        this.noClientWithThatMail = true;
                    }
                    if (clientArr && clientArr.length === 1) {
                        this.noClientWithThatMail = false;
                        this.showItems = true;
                        const client = clientArr[0];
                        this.selectedClient = client;
                        this.clientBookService.getClientBooks(client.id)
                            .subscribe(
                                clientBooks => this.clientBooks = clientBooks,
                                error => this.errorMessage = error)
                    } else {
                        console.log("clientArr ", clientArr);
                    }
                },
                error => this.errorMessage = <any>error);
    }

    save(clientBookForm) {
        let items = clientBookForm.form.value;
        console.log("items: ", items);
        this.clientBookService.saveItems(this.selectedClient.id, items)
            .subscribe(_ => this.goBack());
    }

    private goBack(): void {
        this.location.back();
    }
}