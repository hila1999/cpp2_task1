# מטלה 1 - גרפים (Classes and Namespaces)
function printGraph
הפונקציה קוראת לפונקציה שבודקת כמה קודקודים יש במטריצה
לאחר מכן היא עוברת בשני לולאות על כל התאים שיש במטריצה אם התא שונה מ0 היא מוסיפה אותו למספר הצלעות
אם הגרף הוא לא מכוון אז ספרנו כל צלע פעמיים ולכן היא מחלקת את מספר הצלעות ב2 ומדפיסה את התשובה

function isConnected
הפונקציה בודקת אם הגרף קשיר 
מחזירה 1 אם הגרף קשיר ו0 אם הגרף לא קשיר
the function called to function dfs from vertex 0
אם הגרף הוא קשיר אזי ניתן להגיע מכל קודקוד לכל קודקוד
בפונקציה נאתחל מערך של כל הקודקודים עם הערך FALSE ואז נריץ DFS על כל הקודקודים
כל קודקוד שנבקר אותו יסומן בTRUE
אם בסוף הריצה יש קודקוד שלא ביקרנו בו בריצת ה DFS 
נחזיר FALSE

function shortestPath
 הפונקציה משתמשת באלגוריתם Bellman Ford 
 אנחנו עוברים מספר הקודקודים פחות 1 על כל הצלעות ועושים להם relax
 ולאחר מכן אם קיימת דרך לקודקוד היא הדרך הכי קצרה
  נבדוק אם אין מעגלים שלילים
   אם אין מחזירים את הדרך ע"י שימוש במערך שמחזיק לכל קודקוד 
   מי האבא שמצביע עליו בדרך הקצרה ביותר


function isBipartite
בודקת אם הוא דו צדדי
תחילה בודקת אם הוא מכוון הופעת אותו ללא מכוון
מריצה DFS כדי לבדוק אם יש קודקוד שלא ניתן להגיע אליו
אחרי זה מחלקת את כל קבוצות הקודקודים ל2 קבוצות 
ומחזירה את הקבוצת אם הוא דו צצדי אם לא מחזירה 0

function isContainsCycle
הפונקציה בודקת אם יש מעגל בגרף
 הפונקציה עוברת על כל קודקודי הגרף ומפעילה עליהם DFS ע"י קריאה לפונקציית ISCYCLIC שהיא מבצעת את הבדיקה עבור כל קודקוד
אצלנו היא קוראת לפונקציה isCyclic שבודקת אם קיים מעגל שיוצא מהקודקוד הנשלח


function negativeCycle
הפונקציה בודקת אם יש מעגל שלילי
 הפונקציה משתמשת באלגוריתם Bellman Ford 
אנחנו מריצים בדיקה על כל הצלעות כמספר הקודקודים פחות 1
ואז מבצעים עוד בדיקה על כל הקודקודים אם יש שיפור (RELAX) באחד הצלעות נחזיר שקיים מעגל שלילי ונדפיס אותו
