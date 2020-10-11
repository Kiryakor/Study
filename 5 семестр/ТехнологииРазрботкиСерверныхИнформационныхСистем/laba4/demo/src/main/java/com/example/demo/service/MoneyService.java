package com.example.demo.service;

import com.example.demo.db.model.Money;

public interface MoneyService {

    Iterable<Money> listAll();

    Money add(Integer price, String name, Integer count);

    void delete(Integer id);
}