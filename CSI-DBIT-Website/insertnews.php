<?php
include 'database.php';


$news=$_POST['news'];
$link=$_POST['link']; 
$currdate = date("Y/m/d");
$sql = "INSERT INTO newsfeed VALUES ('$news','$currdate','$link',0)";

 $retval = mysql_query( $sql, $conn );
   
   if(! $retval ) {
      die('Could not get data: ' . mysql_error());
   }				
	echo "<p>News Added</p>";
	echo "<a href='forms.php'>Go Back</a>";
mysql_close($conn);
?>
