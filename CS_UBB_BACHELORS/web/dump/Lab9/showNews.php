
<?php
	$con = mysql_connect("localhost","root","");
	if (!$con) {
		die('Could not connect: ' . mysql_error());
	}

	mysql_select_db("web_programming", $con);
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
