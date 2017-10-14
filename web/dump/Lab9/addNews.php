<?php
	$con = mysql_connect("localhost","root","");
	if (!$con) {
		die('Could not connect: ' . mysql_error());
	}

  $title=$_GET['title'];
  $user=$_GET['username'];
  $category=$_GET['category'];
  $text=$_GET['text'];
    
	mysql_select_db("web_programming", $con);
	mysql_query("INSERT INTO news (textNews,title,user,category,dateNews) VALUES('$text','$title','$user','$category',CURRENT_TIMESTAMP)");
  $result = mysql_query("SELECT * FROM news");

	while($row = mysql_fetch_array($result)){
		echo "<div id=news>";
		echo "<div id=title>" .$row['id'].". ".$row['title']."</div>";
		echo "<div id=details>Added by " . $row['user']." in ".$row['category']." at ".$row['dateNews']."</div>";
		echo "<div id=text>" . $row['textNews']."</div>";
		echo "</div>";
	}
	mysql_close($con);
?> 
