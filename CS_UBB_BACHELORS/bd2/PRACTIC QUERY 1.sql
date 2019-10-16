USE Practic

BEGIN TRAN

UPDATE Chocolate
SET VarietyID = 0
WHERE ChocolateID = 0;

WAITFOR DELAY '00:00:10'

UPDATE Producer
SET Website = 'another.web'
WHERE ProducerID = 0;

COMMIT TRAN