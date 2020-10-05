var app = angular.module('money', [])
//.config(function ($httpProvider) {
//    var csrftoken = $("meta[name='_csrf']").attr("content");
//    var csrfheader = $("meta[name='_csrf_header']").attr("content");
//    $httpProvider.defaults.headers.common["X-CSRF-TOKEN"] = csrftoken;
//});

app.controller("MoneyController", function ($scope, $http) {

    //Get func
    $scope.getMoney = function () {
        $http.get('/public/rest/money').then($scope.successGetMoneyCallback, $scope.errorCallback);
    };

    $scope.successGetMoneyCallback = function (response) {
        $scope.errormessage = ""
        $scope.moneyList = response.data;
    };

    //Delete func
    $scope.deleteMoney = function (id) {
        $scope.deletedId = id;
        $http.delete('/public/rest/money/' + id).then($scope.successDeleteMoneyCallback, $scope.errorCallback);
    };

    $scope.successDeleteMoneyCallback = function (response) {
        $scope.errormessage = ""
        for (var i = 0; i < $scope.moneyList.length; i++) {
            var j = $scope.moneyList[i];
            if (j.id === $scope.deletedId) {
                $scope.moneyList.splice(i, 1);
                break;
            }
        }
    };

    //Post func
    $scope.addMoney = function (price,count,name) {
        $http.post('/public/rest/money/' + name + "/" + price + "/" + count).then($scope.successAddMoneyCallback, $scope.errorCallback);
    };

    $scope.successAddMoneyCallback = function (response) {
        $scope.errormessage = ""
        $http.get('/public/rest/money/').then($scope.successGetMoneyCallback, $scope.errorCallback);
    };

    //Error callback
    $scope.errorCallback = function (error) {
        if (error.status === 400) {
            $scope.errormessage = "Скорей всего какое-то поле не заполнено и сервер не смог удалить данные";
        }
        console.log(error);
    };
});