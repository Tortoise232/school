
<?php
	$con = mysql_connect("localhost","root","");
	if (!$con) {
		die('Could not connect: ' . mysql_error());
	}

  $categ = $_GET["category"];
	$date = $_GET["date"];

	mysql_select_db("web_programming", $con);
	
	if($date==""){
		if($categ=="allnews")
			$result = mysql_query("SELECT * FROM news" );
		else
			$result = mysql_query("SELECT * FROM news WHERE category='" . $categ . "'");
	}
	else {
		if($categ=="allnews")
			$result = mysql_query("SELECT * FROM news WHERE dateNews>='".$date."'" );
		else
			$result = mysql_query("SELECT * FROM news WHERE dateNews>='$date' AND category='" . $categ . "'");
	}

	while($row = mysql_fetch_array($result)){
		echo "<div id=news>";
		echo "<div id=title>" .$row['id'].". ".$row['title']."</div>";
		echo "<div id=details>Added by " . $row['user']." in ".$row['category']." at ".$row['dateNews']."</div>";
		echo "<div id=text>" . $row['textNews']."</div>";
    echo "</div>";
	}
	mysql_close($con);
?> 
