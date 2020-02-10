<?php $dbhost = 'localhost:3036';
   $dbuser = '';
   $dbpass = '';
 $conn = mysql_connect($dbhost, $dbuser, $dbpass);
   mysql_select_db('');
   if(! $conn ) {
      die('Could not connect: ' . mysql_error());
   }
?>
