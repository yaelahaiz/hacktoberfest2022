const waktu = document.querySelector(".Waktu");

// let i = 0;

// const waktuBerjalan = setInterval(function () {
//   i++;
//   waktu.textContent = i;
// }, 1000);

// const WaktuBerhenti = setTimeout(() => {
//   clearInterval(waktuBerjalan);
//   waktu.textContent = "Waktu Berhenti";
// }, 5000);

const interval = setInterval(() => {
  const getNow = new Date().getTime();

  const getTujuan = new Date(`October 26, 2021 15:43:00`);

  const selisihWaktu = getTujuan.getTime() - getNow;

  const hari = selisihWaktu / (1000 * 60 * 60 * 24);
  const getJam = (selisihWaktu % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60);
  const getMenit = (selisihWaktu % (1000 * 60 * 60)) / (1000 * 60);
  const getDetik = (selisihWaktu % (1000 * 60)) / 1000;
  waktu.textContent =
    Math.trunc(hari) +
    " Hari " +
    Math.trunc(getJam) +
    " Jam " +
    Math.trunc(getMenit) +
    " Menit " +
    Math.trunc(getDetik) +
    " Detik";

  if (selisihWaktu <= 0) {
    waktu.textContent = "Diskon Telah Habis";
    clearInterval(interval);
  }
}, 1000);
