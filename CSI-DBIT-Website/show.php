<!DOCTYPE html>
<html>
<head>
<style>
.division {
	border-radius: 5px;
	background-color: #f2f2f2;
	padding: 20px;
	width: 100%;
	margin-left: auto;
	margin-right: auto;
}
table 
{
    font-family: "Courier New",sans-serif;
    border-collapse: collapse;
    width: 100%;
}

td, th 
{
    border: 1px solid #000000;
    text-align: left;
    padding: 8px;
}
th
{
	text-align: center;
}
tr:nth-child(even) 
{
    background-color: #dddddd;
}
</style>
</head>
<body>
<div class="division">
<h1>Show Newsfeed:</h1>
<table>
<tr>
	<th>NID</th>
	<th>News</th>
	<th>Link</th>
	<th>Operation</th>
</tr>
<?php
   include "database.php";
   
   $sql = 'select nid,name,link from newsfeed';
   
   $retval = mysql_query( $sql, $conn );
   
   if(! $retval ) {
      die('Could not get data: ' . mysql_error());
   }
   
   while($row = mysql_fetch_assoc($retval)) 
   {
  	echo "<tr>";
  	echo "<td>" . $row['nid'] . "</td>";
  	echo "<td>" . $row['name'] . "</td>";
  	echo "<td>" . $row['link'] . "</td>";
  	echo "<td><form action='' method='post'><button class='buttonT' type='submit'>Delete</button></form></td>";
  	echo "</tr>";
   }
   mysql_free_result($retval);
   
   mysql_close($conn);   
?>
	  </table>

</div><br>
<div class="division">
<h1>Show CSIWork:</h1>
<table>
<tr>
	<th>NID</th>
	<th>News</th>
	<th>Link</th>
	<th>Operation</th>
</tr>
</div>
</body>
</html>

