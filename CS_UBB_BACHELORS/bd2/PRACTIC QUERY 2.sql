USE Practic

BEGIN TRAN

UPDATE Producer
SET Website = 'another.web'
WHERE ProducerID = 0;

UPDATE Chocolate
SET VarietyID = 0
WHERE ChocolateID = 0;


COMMIT TRAN