var app = angular.module('money', []);

app.controller("MoneyController", function ($scope, $http) {

    $scope.getMoney = function () {
        $http.get('/public/rest/money').then($scope.successGetMoneyCallback, $scope.errorGetMoneyCallback);
    };

    $scope.successGetMoneyCallback = function (response) {
        $scope.moneyList = response.data;
    };

    $scope.errorGetMoneyCallback = function (error) {
        console.log(error);
    };

    $scope.deleteMoney = function (id) {
        $scope.deletedId = id;
        $http.delete('/public/rest/money/' + id).then($scope.successDeleteMoneyCallback, $scope.errorDeleteMoneyCallback);
    };

    $scope.errorDeleteMoneyCallback = function (error) {
        console.log(error);
    };

    $scope.successDeleteMoneyCallback = function (response) {
        for (var i = 0; i < $scope.moneyList.length; i++) {
            var j = $scope.moneyList[i];
            if (j.id === $scope.deletedId) {
                $scope.moneyList.splice(i, 1);
                break;
            }
        }
    };

    $scope.addMoney = function () {
//        $scope.name = "12"
//        $scope.price = 0
//        $scope.count = 1
        $http.post('/public/rest/money/' + $scope.name + "/" + $scope.price + "/" + $scope.count).then($scope.successAddMoneyCallback, $scope.errorAddMoneyCallback);
    };

    $scope.successAddMoneyCallback = function (response) {
        $http.get('/public/rest/money/').then($scope.successGetMoneyCallback, $scope.errorGetMoneyCallback);
    };

    $scope.errorAddMoneyCallback = function (error) {
        console.log(error);
    };
});