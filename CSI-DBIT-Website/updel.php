<?php
include 'database.php';


$name=$_POST['name'];   

$sql = $name;

 $retval = mysql_query( $sql, $conn );
   
   if(! $retval ) {
      die('Could not get data: ' . mysql_error());
   }				
	echo "<p>Database Changes</p>";
	echo "<a href='updatedata.php'>Go Back</a>";
mysql_close($conn);
?>
