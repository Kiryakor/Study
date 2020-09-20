package com.example.demo.HTML;

import com.example.demo.model.Model;

public class HTMLFile {
    static public String allMoneyHTML(Model data){
        String header = "<html>\n" +
                "<header>" +
                    "<title>Магазин монеток</title>" +
                "</header>\n" +
                "<body>\n";
        String tableContent = "";
        tableContent += "<h1>Магазин монеток</h1>\n";
        for (int i=0;i<data.getData().size();i++) {
            tableContent += "<a href=\"http://localhost:8080/money/" + i + "\">" +
                    "<h3>" + data.getData().get(i).getName() + "</h3>" +
                    "</a>\n";
        }
        String bottom = "</body>\n" +
                        "</html>";
        return  header + tableContent + bottom;
    }

    static public String moneyHTML(Model.DataMoney data){
        return "<html>\n" +
                "<header>" +
                    "<title>" + data.getName() + "</title>" +
                "</header>\n" +
                "<body>\n" +
                    "<img src=\"" + data.getHref() + "\">\n" +
                    "<h1>" + data.getName() + "</h1>\n" +
                    "<h1>" + data.getCount() + "</h1>\n" +
                    "<h1>" + data.getPrice()+ "</h1>\n" +
                "</body>\n" +
                "</html>";
    }

    static public String mainHTML(){
        return "<html>\n" +
                "<header>" +
                    "<title>Главная страница</title>" +
                "</header>\n" +
                "<body>\n" +
                    "<h1>Магазин монеток</h1>\n" +
                    "<a href=\"http://localhost:8080/money\"><h3>Просмотр всех данных</h3></a>\n" +
                    "<a href=\"http://localhost:8080/add\"><h3>Добавить новые данные</h3></a>\n" +
                    "<a href=\"http://localhost:8080/delete\"><h3>Удалить данные</h3></a>\n" +
                "</body>\n" +
                "</html>";
    }

    static public String addHTML(){
        return  "<html>\n" +
                "<header>" +
                    "<title>Добавление данных</title>" +
                "</header>\n" +
                "<body>\n" +
                    "<h1>Магазин монеток</h1>\n" +
                    "<form action=\"/add\" method=\"post\" value=\"add\">" +
                        "<input type=\"text\" name=\"href\" placeholder=\"Ссылка на фотографию\"><br><br>" +
                        "<input type=\"text\" name=\"price\" placeholder=\"Цена\"><br><br>" +
                        "<input type=\"text\" name=\"count\" placeholder=\"Количество\"><br><br>" +
                        "<input type=\"text\" name=\"name\" placeholder=\"Название\"><br><br>" +
                        "<button type=\"submit\" name=\"button\" value=\"add\">Добавить новую монету в коллекцию</button>" +
                    "</form>" +
                "</body>\n" +
                "</html>";
    }

    static public String deleteHTML(){
        return "<html>\n" +
                "<header>" +
                    "<title>Добавление данных</title>" +
                "</header>\n" +
                "<body>\n" +
                    "<h1>Магазин монеток</h1>\n" +
                    "<form action=\"/delete\" method=\"post\">" +
                        "<input type=\"text\" name=\"remove\" placeholder=\"Название монеты\"><br><br>" +
                        "<button type=\"submit\" name=\"button\" value=\"delete\">Удалить данные</button>" +
                    "</form>\n" +
                "</body>\n" +
                "</html>";
    }
}
