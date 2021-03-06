/**
 * Created by tudor on 4/13/2017.
 */
"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
        var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
        if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
        else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
        return c > 3 && r && Object.defineProperty(target, key, r), r;
    };
var core_1 = require('@angular/core');
require('rxjs/add/operator/switchMap');
var ClientDetailComponent = (function () {
    function ClientDetailComponent(clientService, route, location) {
        this.clientService = clientService;
        this.route = route;
        this.location = location;
    }
    ClientDetailComponent.prototype.ngOnInit = function () {
        var _this = this;
        this.route.params
            .switchMap(function (params) { return _this.clientService.getDiscipline(+params['id']); })
            .subscribe(function (client) { return _this.client = client; });
    };
    ClientDetailComponent.prototype.goBack = function () {
        this.location.back();
    };
    __decorate([
        core_1.Input()
    ], ClientDetailComponent.prototype, "client", void 0);
    ClientDetailComponent = __decorate([
        core_1.Component({
            selector: 'ubb-client-detail',
            templateUrl: './client-detail.component.html',
            styleUrls: ['./client-detail.component.css'],
        })
    ], ClientDetailComponent);
    return ClientDetailComponent;
}());
exports.ClientDetailComponent = ClientDetailComponent;
