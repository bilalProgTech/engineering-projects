
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

input[type=text], [type=email], select, [type=password] {
	width: 100%;
	padding: 12px 20px;
	margin: 8px 0;
	display: inline-block;
	border: 1px solid #ccc;
	border-radius: 4px;
	box-sizing: border-box;
}

input[type=submit], button {
	width: 100%;
	background-color: #909497;
	color: black;
	padding: 14px 20px;
	margin: 8px 0;
	border: none;
	border-radius: 4px;
	cursor: pointer;
}

input[type=submit]:hover {
	background-color: #626567;
}

textarea {
	border: 1px solid #ccc;
	border-radius: 4px;
	width: 100%;
	margin: 8px 0;
	display: inline-block;
}

input[type=text], [type=email], select, textarea {
	font-family: Times New Roman;
	font-size: 25;
}
</style>
</head>
<body>
<?php

?>
	<p style="text-align: left">
		<a href="forms.php">Insert |</a> <a href="updatedata.php">UpDel |</a><a
			href="logout.php">Logout</a>
	</p>
	<br>
	<div class="division">
		<h1>Slideshow</h1>
		<form action="uploadimage.php" method="post"
			enctype="multipart/form-data">
			Enter your file: <input type="file" name="file"> <input
				type="submit" value="Store">
		</form>
	</div>
	<br>
	<div class="division">
		<h1>Newsfeed</h1>
		<form action="insertnews.php" method="post"
			enctype="multipart/form-data">
			News :<br>
			<input type="text" name="news"> <br> Any Link: <br>
			<input type="text" name="link"><br> <input
				type="submit" value="Store">
		</form>
	</div>
	<br>

	<div class="division">
		<h1>PHP Files</h1>
		<form action="indexphp.php" method="post"
			enctype="multipart/form-data">
			Store your file here :<br>
			<input type="file" name="file"> <br> <input
				type="submit" value="Store">
		</form>
	</div>
	<br>
	<div class="division">
		<h1>CSI Work</h1>
		<form action="work.php" method="post" enctype="multipart/form-data">
			Event Name: <input type="text" name="name"> <br>
			Conducted By: <input type="text" name="conduct"><br>
			Footfall: <input type="text" name="footfall"><br>

			Document:<br> <input type="file" name="file"><br>
			<input type="submit" value="Store">
		</form>
	</div>
	<br>
</body>
</html>

