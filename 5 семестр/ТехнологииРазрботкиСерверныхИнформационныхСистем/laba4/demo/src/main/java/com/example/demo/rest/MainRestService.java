package com.example.demo.rest;

import com.example.demo.service.MoneyService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

//MARK: - Добавить проверку на ауф

@RestController
@RequestMapping("/public/rest/money")
public class MainRestService {

    @Autowired
    private MoneyService moneyService;

    @RequestMapping(value = "", method = RequestMethod.GET)
    public ResponseEntity<Object> browse() {
        return ResponseEntity.ok(moneyService.listAll());
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.DELETE)
    public void delete(@PathVariable("id") Integer id) {
        moneyService.delete(id);
    }

    @RequestMapping(value = "/{name}/{price}/{count}", method = RequestMethod.POST)
    public ResponseEntity<Object> add(@PathVariable("name") String name,
                                      @PathVariable("price") Integer price,
                                      @PathVariable("count") Integer count) {
        return ResponseEntity.ok(moneyService.add(price, name, count));
    }
}