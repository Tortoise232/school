/**
 * Created by cata on 23.04.2017.
 */

import {Component,OnInit} from "@angular/core";
import {Router} from "@angular/router";

import {Client} from "../shared/client.model"
import {ClientService} from "../shared/client.service";

@Component({
  moduleId:module.id,
  selector: 'dot-client-list',
  templateUrl:'./client-list.component.html',
  styleUrls:['./client-list.component.css'],
})
export class ClientListComponent implements  OnInit
{
  errorMessage: string;
  clients: Client[];
  selectedClinet: Client;

  constructor (private clientService:ClientService,private router:Router)
  {

  }
  ngOnInit(): void {
  this.getClients();
  }

  getClients()
  {
    this.clientService.getClients().subscribe(clients=>this.clients=clients,error=> this.errorMessage=<any>error);

  }
  onSelect(client :Client):void
  {
    this.selectedClinet=client;
  }

  gotoDetail():void
  {

    this.router.navigate(['/client/detail',this.selectedClinet.id]);
  }

  delete(client:Client):void
  {
    this.clientService.delete(client.id).subscribe(()=>{
      this.clients=this.clients.filter(c=>c!=client);
      if(this.selectedClinet === client)
        this.selectedClinet=null;
    });
  }
  create():void
  {
    this.router.navigate(['client/create']);
  }
}