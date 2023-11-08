# Write your MySQL query statement below
select activity_date as day, count(distinct user_id) as active_users from activity
group by activity_date
having 0<datediff('2019-07-27',activity_date) and datediff('2019-07-27',activity_date)<30;