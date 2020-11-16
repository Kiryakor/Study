package com.example.demo.db.dao;

import com.example.demo.db.model.Money;
import org.springframework.data.repository.CrudRepository;

public interface MoneyRepository extends CrudRepository<Money, Integer> {}