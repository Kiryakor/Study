package com.example.demo.db.model;

import lombok.AllArgsConstructor;
import lombok.Data;
import javax.persistence.*;
import java.io.Serializable;

//Entity это легковесный хранимый объект бизнес логики (persistent domain object).
//Основная программная сущность это entity класс, который так же может использовать дополнительные классы,
//который могут использоваться как вспомогательные классы или для сохранения состояния еntity.
//1) Entity класс должен быть отмечен аннотацией Entity или описан в XML файле конфигурации JPA,
//2) Entity класс должен содержать public или protected конструктор без аргументов
// он также может иметь конструкторы с аргументами),
//3) Entity класс должен быть классом верхнего уровня (top-level class),
//4) Entity класс не может быть enum или интерфейсом,
//5) Entity класс не может быть финальным классом (final class),
//6) Entity класс не может содержать финальные поля или методы, если они участвуют в маппинге
//(persistent final methods or persistent final instance variables),
//7) Если объект Entity класса будет передаваться по значению как отдельный объект (detached object),
// например через удаленный интерфейс (through a remote interface), он так же должен реализовывать Serializable интерфейс,
//8) Поля Entity класс должны быть напрямую доступны только методам самого Entity класса и не должны быть напрямую доступны другим классам,
// использующим этот Entity. Такие классы должны обращаться только к методам (getter/setter методам или другим методам бизнес-логики в Entity классе),
//9) Enity класс должен содержать первичный ключ, то есть атрибут или группу атрибутов которые уникально определяют запись этого Enity класса в базе данных,
@Entity
@Table(name = "MONEY")
@Data
@AllArgsConstructor
public class Money implements Serializable {

    public Money(Integer cost, String name,Integer count) {
        this.cost = cost;
        this.name = name;
        this.count = count;
    }

    public Money(){}

    @Id
    @Column(name = "MONEY_ID")
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer id;

    @Column(name = "MONEY_COST")
    private Integer cost;

    @Column(name = "MONEY_COUNT")
    private Integer count;

    @Column(name = "MONEY_NAME")
    private String name;
}
