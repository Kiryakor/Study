package com.example.demo.сontrollers;

import com.example.demo.common.helpers.ConvertData;
import com.example.demo.model.MainModel;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("")
public class MainController extends HttpServlet {

    MainModel data = new MainModel();

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {
        processRequest(resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {
        String button = req.getParameter("button");

        System.out.println(button);
        if ("delete".equals(button)) {
            data.removeData(req.getParameter("remove"));
        } else if ("add".equals(button)) {
            data.addData(prepareDataToAdd(req));
        }

        processRequest(resp);
    }

    //MARK: - Подготовка данных для добавление
    MainModel.DataMoney prepareDataToAdd(HttpServletRequest req){
        String href = req.getParameter("href");
        String price = req.getParameter("price");
        String count = req.getParameter("count");
        String name = req.getParameter("name");

        int intPrice = ConvertData.convertStringToInt(price);
        int intCount = ConvertData.convertStringToInt(count);

        return new MainModel.DataMoney(href,intPrice,intCount,name);
    }

    //MARK: шаблонная функция html
    protected void processRequest(HttpServletResponse response)
            throws IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            out.print("<!DOCTYPE html>\n" +
                    "<html lang=\"en\">\n" +
                    "    <head>\n" +
                    "        <meta charset=\"UTF-8\">\n" +
                    "        <title>Коллекционирование (нумизматика, филателия и пр).</title>\n" +
                    "        <style>\n" +
                    "            table {\n" +
                    "                border-spacing: 0 10px;\n" +
                    "                font-family: 'Open Sans', sans-serif;\n" +
                    "                font-weight: bold;\n" +
                    "            }\n" +
                    "            th {\n" +
                    "                padding: 10px 20px;\n" +
                    "                background: #56433D;\n" +
                    "                color: #F9C941;\n" +
                    "                border-right: 2px solid;\n" +
                    "                font-size: 0.9em;\n" +
                    "            }\n" +
                    "            th:first-child {\n" +
                    "                text-align: left;\n" +
                    "            }\n" +
                    "            th:last-child {\n" +
                    "                border-right: none;\n" +
                    "            }\n" +
                    "            td {\n" +
                    "                vertical-align: middle;\n" +
                    "                padding: 10px;\n" +
                    "                font-size: 14px;\n" +
                    "                text-align: center;\n" +
                    "                border-top: 2px solid #56433D;\n" +
                    "                border-bottom: 2px solid #56433D;\n" +
                    "                border-right: 2px solid #56433D;\n" +
                    "            }\n" +
                    "            td:first-child {\n" +
                    "                border-left: 2px solid #56433D;\n" +
                    "                border-right: none;\n" +
                    "            }\n" +
                    "            td:nth-child(2){\n" +
                    "                text-align: left;\n" +
                    "            }\n" +
                    "        </style>\n" +
                    "    </head>");
            out.println("<body>");
            out.println("<div align=\"center\">");
            out.println("<h1>Коллекционирование монет</h1>");
            out.println("<table>");
            out.println("<tr>");
            out.println("<th colspan=\"2\">Монета</th>");
            out.println("<th>Цена</th>");
            out.println("<th>Количество</th>");
            out.println("<th>Название монеты</th>");
            out.println("</tr>");
            for (MainModel.DataMoney i : data.getData()) {
                out.println("<tr>");
                out.println("<td><img src=" + i.href + " width=100 height=100</td>");
                out.println("<td></td>");
                out.println("<td>" + i.price + "</td>");
                out.println("<td>" + i.count + "</td>");
                out.println("<td>" + i.name + "</td>");
                out.println("</tr>");
            }
            out.println("</table>");

            out.println("<table>");
            out.println("<tr>");
            out.println("<td>");
            out.print("<form action=\"/\" method=\"post\" value=\"add\">");
            out.print("<input type=\"text\" name=\"href\" placeholder=\"Ссылка на фотографию\"><br>");
            out.print("<input type=\"text\" name=\"price\" placeholder=\"Цена\"><br>");
            out.print("<input type=\"text\" name=\"count\" placeholder=\"Количество\"><br>");
            out.print("<input type=\"text\" name=\"name\" placeholder=\"Название\"><br>");
            out.print("<button type=\"submit\" name=\"button\" value=\"add\">Добавить новую монету в коллекцию</button>");
            out.print("</form>");
            out.println("</td>");
            out.println("<td>");
            out.println("</td>");
            //MARK: - Удаление данных
            out.println("<td>");
            out.print("<form action=\"/\" method=\"post\">");
            out.print("<input type=\"text\" name=\"remove\" placeholder=\"Название монеты\"><br>");
            out.print("<button type=\"submit\" name=\"button\" value=\"delete\">Удалить данные</button>");
            out.print("</form>");
            out.println("</td>");
            out.println("</tr>");
            out.println("</table>");

            out.println("</body>");
            out.println("</html>");
        }
    }
}