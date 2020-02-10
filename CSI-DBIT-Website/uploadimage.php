<?php
include 'database.php';
$target_path = "/var/www/html/csi/"; 
$file =$_FILES['file']['name'];
$target_path = $target_path.basename( $_FILES['file']['name']);   
  
if(move_uploaded_file($_FILES['file']['tmp_name'], $target_path)) 
{  
    echo "File uploaded successfully!";  
$sql = "INSERT INTO slides VALUES ('$file')";

 $retval = mysql_query( $sql, $conn );
   
   if(! $retval ) {
      die('Could not get data: ' . mysql_error());
   }				
	echo "<p>Image Added</p>";
	echo "<a href='forms.php'>Go Back</a>";
mysql_close($conn);
} else{  
    echo "Sorry, file not uploaded, please try again!";  
}
?>
