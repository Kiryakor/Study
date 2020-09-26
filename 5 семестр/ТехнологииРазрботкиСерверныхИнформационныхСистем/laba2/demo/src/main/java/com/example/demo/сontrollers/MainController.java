package com.example.demo.сontrollers;

import com.example.demo.helpers.JsonParser;
import com.example.demo.model.Model;
import org.json.JSONException;
import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("")
public class MainController {

    Model data;

    MainController(){
        data = new Model();
    }

    @ResponseBody
    @RequestMapping(value = "/money", method = RequestMethod.POST)
    public HttpStatus postAdd(@RequestBody String myModel) throws JSONException {
        Model.DataMoney data = JsonParser.postMoney(myModel);
        this.data.addData(data);
        return HttpStatus.OK;
    }

    @ResponseBody
    @RequestMapping(value = "/money", method = RequestMethod.DELETE)
    public HttpStatus getDelete(@RequestBody String name) throws JSONException {
        if (data.removeData(name))
            return HttpStatus.FOUND;
        else
            return HttpStatus.NOT_FOUND;
    }

    @RequestMapping(value = "/money", method = RequestMethod.GET)
    public String getMoneyInfo() throws JSONException {
        return JsonParser.getAllMoney(data.getData()).toString();
    }

    @RequestMapping(value = "/money/{id}", method = RequestMethod.GET)
    public String getMoneyInfo(@PathVariable("id") int id) throws JSONException {
        return JsonParser.getMoney(data.getData().get(id)).toString();
    }
}