<?php
include 'database.php';


$name=$_POST['name'];
$email=$_POST['email'];
$phone = $_POST['phone'];
$post = $_POST['post'];
$photo = $_FILES['pic'];
$year = $_POST['year'];

$file = $photo['name'];

$path = "/var/www/html/csi/" . basename($file); // 5
    if (move_uploaded_file($file['tmp_name'], $path)) {
	echo "File Uploaded";
    } else {

    }

$sql = "INSERT INTO committee VALUES ('$name','$email','$phone','$post','$file','$year')";

 $retval = mysql_query( $sql, $conn );
   
   if(! $retval ) {
      die('Could not get data: ' . mysql_error());
   }				
	echo "<p>Student Added</p>";
	echo "<a href='forms.php'>Go Back</a>";
mysql_close($conn);
?>
