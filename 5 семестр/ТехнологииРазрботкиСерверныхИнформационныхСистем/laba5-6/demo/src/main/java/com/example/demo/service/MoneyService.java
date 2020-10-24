package com.example.demo.service;

import com.example.demo.db.model.Money;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UsernameNotFoundException;

public interface MoneyService {

    Iterable<Money> listAll();

    Money add(Integer price, String name, Integer count);

    void delete(Integer id);

    void add(Money money);
}