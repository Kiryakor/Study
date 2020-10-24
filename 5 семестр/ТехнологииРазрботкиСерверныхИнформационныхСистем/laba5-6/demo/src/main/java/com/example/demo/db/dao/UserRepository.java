package com.example.demo.db.dao;

import com.example.demo.db.model.User;
import org.springframework.data.repository.CrudRepository;

public interface UserRepository extends CrudRepository<User, Integer> {
    User findByLogin(String login);
}