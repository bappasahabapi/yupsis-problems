  // Problem 3: Message Processing with Retry Logic (Random ID Validation)
// fronted part


const payments = [];
const retryDelays = [1000, 2000, 3000, 4000, 5000, 6000];


function generateRandomTransaction() {
  const id = Math.floor(Math.random() * 10); // 0-9
  const amount = Math.floor(Math.random() * (1000 - 10 + 1)) + 10;

  return {
    trxId: id,
    amount,
    timestamp: new Date().toISOString(),
    status: 'pending',
    attemptCount: 0
  };
}


const generateInterval = setInterval(() => {
  const trx = generateRandomTransaction();
  payments.push(trx);
  console.log("New transaction added:", trx);
}, 1000);


setTimeout(() => {
  clearInterval(generateInterval);
  console.log("⏹ Stopped generating transactions after 5 seconds.");
  console.log("                     ");
  
}, 5000);


function validateTransaction(trx) {
  const random = Math.floor(Math.random() * 10);
  console.log(`🔍 Validating trxId: ${trx.trxId} against random: ${random}`);
  return trx.trxId === random;
}

let isProcessing = false;

function processNextTransaction() {
  if (isProcessing) return;

  const trx = payments.find(t =>
    t.status === 'pending' || (t.status === 'rejected' && t.attemptCount < retryDelays.length)
  );

  if (!trx) return checkIfAllDone();

  isProcessing = true;
  trx.status = 'processing';

  setTimeout(() => {
    const isValid = validateTransaction(trx);

    if (isValid) {
      trx.status = 'success';
      console.log(`✅ Transaction ${trx.trxId} succeeded.`);
    } else {
      trx.status = 'rejected';
      trx.attemptCount++;
      console.log(`❌  Transaction ${trx.trxId} failed (Attempt ${trx.attemptCount}).`);

      if (trx.attemptCount < retryDelays.length) {
        const retryDelay = retryDelays[trx.attemptCount];
        console.log(`⏳ Retrying transaction ${trx.trxId} in ${retryDelay}ms`);
        return setTimeout(() => {
          trx.status = 'pending';
          isProcessing = false;
          processNextTransaction();
        }, retryDelay);
      } else {
        console.log(`⚠️ Transaction ${trx.trxId} permanently failed after ${trx.attemptCount} attempts.`);
      }
    }

    isProcessing = false;
    console.table(payments, ['trxId', 'status', 'attemptCount', 'timestamp']);
    processNextTransaction(); 
  }, 0);
}

function checkIfAllDone() {
  const allFinal = payments.length > 0 && payments.every(t =>
    t.status === 'success' || (t.status === 'rejected' && t.attemptCount >= retryDelays.length)
  );

  if (allFinal) {
    console.log("--------- All transactions processed. Program will now exit.--------------------------");
    process.exit(0); 
  }
}

const processingInterval = setInterval(() => {
  processNextTransaction();
}, 1000);
