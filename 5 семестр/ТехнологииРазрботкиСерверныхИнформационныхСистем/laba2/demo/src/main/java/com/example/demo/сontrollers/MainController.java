package com.example.demo.сontrollers;

import com.example.demo.helpers.ConvertData;
import com.example.demo.helpers.JsonParser;
import com.example.demo.model.Model;
import org.json.JSONException;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("")
public class MainController {

    Model data;

    MainController(){
        data = new Model();
    }

    //MARK: - Add
    @RequestMapping(value = "/money", method = RequestMethod.POST)
    public String postAdd(@RequestParam(value = "href",required = false) String href,
                          @RequestParam(value = "price",required = false) String price,
                          @RequestParam(value = "count",required = false,defaultValue = "1") String count,
                          @RequestParam("name") String name) {
        data.addData(new Model.DataMoney(href, ConvertData.convertStringToInt(price),ConvertData.convertStringToInt(count),name));
        return "Success";
    }

    //MARK: - Remove - параметр для удаления какой-нибудь добавить
    @RequestMapping(value = "/money", method = RequestMethod.DELETE)
    public String getDelete(@RequestParam String name) {
        if (data.removeData(name))
            return "Success";
        else
            return "No success";
    }

    //MARK: - All money view
    @RequestMapping(value = "/money", method = RequestMethod.GET)
    public String getMoneyInfo() throws JSONException {
        return JsonParser.getAllMoney(data.getData()).toString();
    }

    //MARK: - Detail money view
    @RequestMapping(value = "/money/{id}", method = RequestMethod.GET)
    public String getMoneyInfo(@PathVariable("id") int id) throws JSONException {
        return JsonParser.getMoney(data.getData().get(id)).toString();
    }
}