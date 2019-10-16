<?php
	$con = mysql_connect("localhost","root","");
	if (!$con) {
		die('Could not connect: ' . mysql_error());
	}

  $id=$_GET['id'];
  $title=$_GET['title'];
  $user=$_GET['user'];
  $text=$_GET['text'];
  $category=$_GET['category'];
    
	mysql_select_db("web_programming", $con);
	mysql_query("UPDATE news SET title = '$title', textNews='$text',user='$user',category='$category' WHERE id = $id");
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
