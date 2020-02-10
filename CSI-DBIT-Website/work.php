<?php
include 'database.php';


$name=$_POST['name'];
$conduct=$_POST['conduct'];
$footfall=$_POST['footfall'];
$file =$_FILES['file']['name'];
$target_path = "/var/www/html/csi/pdf/";  
$target_path = $target_path.basename( $_FILES['file']['name']);   
  
if(move_uploaded_file($_FILES['file']['tmp_name'], $target_path)) {  
    echo "File uploaded successfully!";  
} else{  
    echo "Sorry, file not uploaded, please try again!";  
}
$sql = "INSERT INTO csiwork VALUES ('$name','$conduct',$footfall,'$file',0)";

 $retval = mysql_query( $sql, $conn );
   
   if(! $retval ) {
      die('Could not get data: ' . mysql_error());
   }				
	echo "<p>Work Added</p>";
	echo "<a href='forms.php'>Go Back</a>";
mysql_close($conn);
?>
