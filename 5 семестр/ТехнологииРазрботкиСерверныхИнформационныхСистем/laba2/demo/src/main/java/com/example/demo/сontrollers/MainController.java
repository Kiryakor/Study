package com.example.demo.сontrollers;

import com.example.demo.HTML.HTMLFile;
import com.example.demo.helpers.ConvertData;
import com.example.demo.model.Model;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("")
public class MainController {

    Model data;

    MainController(){
        data = new Model();
    }

    //MARK: -  Main
    @RequestMapping(value = "", method = RequestMethod.GET)
    public String getMain() {
        return HTMLFile.mainHTML();
    }

    //MARK: - Add
    @RequestMapping(value = "/add", method = RequestMethod.GET)
    public String getAdd() {
        return HTMLFile.addHTML();
    }

    @RequestMapping(value = "/add", method = RequestMethod.POST)
    public String postAdd(@RequestParam("href") String href,
                          @RequestParam("price") String price,
                          @RequestParam("count") String count,
                          @RequestParam("name") String name) {
        data.addData(new Model.DataMoney(href, ConvertData.convertStringToInt(price),ConvertData.convertStringToInt(count),name));
        return HTMLFile.addHTML();
    }

    //MARK: - Remove
    @RequestMapping(value = "/delete", method = RequestMethod.GET)
    public String getDelete() {
        return HTMLFile.deleteHTML();
    }

    @RequestMapping(value = "/delete", method = RequestMethod.POST)
    public String postDelete(@RequestParam("remove") String remove) {
        data.removeData(remove);
        return HTMLFile.deleteHTML();
    }

    //MARK: - All money
    @RequestMapping(value = "/money", method = RequestMethod.GET)
    public String getMoneyInfo() {
        return HTMLFile.allMoneyHTML(data);
    }

    //MARK: - Detail money
    @RequestMapping(value = "/money/{id}", method = RequestMethod.GET)
    public String getMoneyInfo(@PathVariable("id") int id) {
        return HTMLFile.moneyHTML(data.getData().get(id));
    }
}