SELECT a.title,a.year FROM movies as a
WHERE (SELECT COUNT(*) FROM movies NATURAL JOIN movieawards WHERE movieawards.title=a.title AND movieawards.award='%oscar%' AND movieawards.result='won')
= (SELECT MAX((SELECT COUNT(*) FROM movies as b NATURAL JOIN movieawards WHERE movieawards.title=b.title AND movieawards.award like '%oscar%' AND movieawards.result='won')))
ORDER BY a.title,a.year;