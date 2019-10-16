USE [MiniFacebook]
GO

DROP TABLE Likes
DROP TABLE Comments
DROP TABLE Posts
DROP TABLE Users
DROP TABLE Pages
DROP TABLE Categories
GO

CREATE TABLE Categories(
	 CategoryID INT PRIMARY KEY,
	 CName VARCHAR(50),
	 CDescription VARCHAR(500))

CREATE TABLE Pages(
	PageID INT PRIMARY KEY,
	PName VARCHAR(50),
	CategoryID INT REFERENCES Categories(CategoryID))

CREATE TABLE Users(
	UserID INT PRIMARY KEY,
	UName VARCHAR(50),
	UCity VARCHAR(50),
	UDOB DATE)

CREATE TABLE Posts(
	PostID INT PRIMARY KEY,
	PoText VARCHAR(500),
	PoDate DATE,
	Shares INT,
	UserID INT REFERENCES Users(UserID))

CREATE TABLE Comments(
	CommentID  INT PRIMARY KEY,
	CoText VARCHAR(500),
	CoDate DATE,
	IsTopComm BIT,
	PostID INT REFERENCES Posts(PostID))

CREATE TABLE Likes(
	UserID INT REFERENCES Users(UserID),
	PageID INT REFERENCES Pages(PageID),
	LiDate DATE
	)
/* 
Users
Uid
UName
UCity
UDoB

Likes
UserID FK Users.Uid
PageID FK Pages.PID
Date

Posts
PostID
UserID FK Users.Uid
PostDate
PostText
NumberOfShares

Comments
CommentID
CommentDate
CommentText
IsTopComment (bool)
PostID FK Posts.PostID

Pages
PId
PName
CategoryID FK Categories.CID

Categories
CID
CName
CDescription

*/


SET TRANSACTION ISOLATION LEVEL REPEATABLE READ
SET TRANSCATION ISOLATION LEVEL READ COMMITED 
begin tran update posts
set potext = 'deksfuhoas'
where postid = 1

update users 


