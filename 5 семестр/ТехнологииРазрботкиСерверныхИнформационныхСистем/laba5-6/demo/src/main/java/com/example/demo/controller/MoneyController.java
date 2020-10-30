package com.example.demo.controller;

import com.example.demo.db.model.Money;
import com.example.demo.service.MoneyService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class MoneyController {

    @Autowired
    MoneyService moneyService;

    @RequestMapping(value = "/money", method = RequestMethod.GET)
    public ModelAndView getMoney(){
        return CommonBlock();
    }

    @RequestMapping(value = "/money/{id}", method = RequestMethod.GET)
    public ModelAndView getMoneyID(){
        return CommonBlock();
    }

    @RequestMapping(value = "/money", method = RequestMethod.POST)
    public ModelAndView postMoney(@ModelAttribute("AddMoney") Money money){
        moneyService.add(money);
        return CommonBlock();
    }

    @RequestMapping(value = "/money/{id}", method = RequestMethod.POST)
    public ModelAndView postMoneyID(@PathVariable("id") Integer id){
        moneyService.delete(id);
        return CommonBlock();
    }

    ModelAndView CommonBlock(){
        ModelAndView mav = new ModelAndView("money5");
        mav.addObject("AllMoney",moneyService.listAll());
        mav.addObject("AddMoney",new Money());
        return mav;
    }
}
