package com.example.demo.db.model;

import javax.persistence.*;
import lombok.Data;

@Entity
@Table(name = "USR")
@Data
public class User {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "USR_ID", nullable = false, updatable = false)
    private Long id;

    @Column(name = "USR_LOGIN", nullable = false)
    private String login;

    @Column(name="USR_PASS_HASH", nullable = false)
    private String passHash;

    public String getLogin() {
        return  login;
    }

    public String getPassHash() {
        return  passHash;
    }
}