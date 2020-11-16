package com.example.demo.service;

import com.example.demo.db.dao.MoneyRepository;
import com.example.demo.db.model.Money;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class MoneyServiceImpl implements MoneyService {

    @Autowired
    private MoneyRepository moneyRepository;

    @Override
    public Iterable<Money> listAll() {
        return moneyRepository.findAll();
    }

    @Override
    public void delete(Integer id) {
        moneyRepository.deleteById(id);
    }

    @Override
    public Money add(Integer number, String name, Integer count) {
        return moneyRepository.save(new Money(number, name, count));
    }
}
