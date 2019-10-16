/**
 * Created by tudor on 5/1/2017.
 */
import {Component, Input, OnInit} from "@angular/core";
import {Location} from '@angular/common';

import {Client} from "../shared/client.model";
import {ClientService} from "../shared/client.service";
import { FormBuilder, FormGroup } from '@angular/forms';
import {Response} from "@angular/http";


@Component({
    moduleId: module.id,
    selector: 'ubb-client-new',
    templateUrl: './client-new.component.html',
    styleUrls: ['./client-new.component.css'],
})

export class ClientNewComponent{
    @Input() client: Client;

    constructor(private clientService: ClientService,
                private location: Location) {
    }

    goBack(): void {
        this.location.back();
    }

    saveAttempt = false;

    initSave(){
        this.saveAttempt = true;
    }

    //showRegistrationStatus(status: string): void{
        //if(status == "Created"){
        //    let success = document.getElementById("success");
        //    let form = document.getElementById("register-form");
        //    form.style.display = "none";
        //    success.style.display = "block";
        //}
        //if(status == "IM Used"){
        //    let failure = document.getElementById("failure");
        //    failure.style.display = "block";
        //}
    //}

    save(firstName, lastName, email, address): void {
        console.log("Adding client ", firstName, lastName, email, address);
        this.clientService.create(firstName, lastName, email, address).subscribe(_ => this.goBack());
            //.subscribe(c => this.showRegistrationStatus(c));
    }
}