select b.id from weather as a inner join weather as b
on b.recordDate=date_add(a.recordDate, interval 1 day) and a.temperature<b.temperature;