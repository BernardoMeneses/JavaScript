import * as THREE from 'https://unpkg.com/three@0.126/build/three.module.js';
import { OrbitControls } from 'https://unpkg.com/three@0.126/examples/jsm/controls/OrbitControls.js';
import { setupLightKeybinds, setupMovementKeybinds, setupMenuKeybinds } from './keybinds.js';
import TWEEN from 'https://cdn.jsdelivr.net/npm/@tweenjs/tween.js@18.6.4/dist/tween.esm.js';
import confetti from 'https://cdn.jsdelivr.net/npm/canvas-confetti@1.4.0/dist/confetti.module.mjs';
import { createSofa } from './Objetos/sofa.js'
import { createQuadroGroup, addQuadroGroupToWall } from './Objetos/quadros.js';
import { createPorta, rotatePortaY } from './Objetos/porta.js';
import { createPlanta } from './Objetos/planta.js';
import { createGraffiti } from './Objetos/graffiti.js';
import { createTV } from './Objetos/tv.js';
import { createCandeeiro } from './Objetos/candeeiro.js';


const scene = new THREE.Scene();


// Adicionando o sofá à cena
const sofa = createSofa();
sofa.position.set(1, -5.5, -45); // Ajuste a posição conforme necessário
scene.add(sofa);

const sofa1 = createSofa();
sofa1.position.set(16,-5.5, -45 );
scene.add(sofa1);

const porta = createPorta({ x: 50, y: 0, z: 40 }, './Texturas/mesa.png');
scene.add(porta);

// Adicionando planta à cena ao lado da porta
const planta = createPlanta({ x: 45, y: -5, z: 0 }, './Texturas/vaso.jpg', './Texturas/planta.jpg');
scene.add(planta);

const aspect = window.innerWidth / window.innerHeight;
const frustumSize = 20;

// Array de dicas
const dicas = [
    "Dica: Tenta conectar 4 peças da mesma cor!",
    "Dica: O que importa é ter saúde mesmo ganhando ou perdendo",
    "Dica: Destroi o teu oponente e impede o de jogar",
    "Dica: Planeia bem as tuas jogadas",
    "Dica: Este jogo tem o selo de aprovação do Zeca, é Zecástico",
    "Dica: Os alunos da UTAD fazem os melhores jogos e gameplays",
    "Dica: Patricionado pela AllSoft e Companhia"
];

// Função para selecionar uma dica aleatória
function getDicaAleatoria() {
    const indiceAleatorio = Math.floor(Math.random() * dicas.length);
    return dicas[indiceAleatorio];
}

// Criação do ambiente da sala de estar
const textureLoader = new THREE.TextureLoader();
const wallTexture = textureLoader.load('Texturas/wall.jpg');
const floorTexture = textureLoader.load('Texturas/floor.jpg');


// Materiais
const roomMaterial = new THREE.MeshPhongMaterial({ map: wallTexture, side: THREE.DoubleSide });
const roomDepth = 100;
const roomWidth = 100;
const roomHeight = 40;

// Chão
const floorGeometry = new THREE.PlaneGeometry(roomWidth, roomDepth);
const floor = new THREE.Mesh(floorGeometry, new THREE.MeshPhongMaterial({  map: floorTexture }));
floor.rotation.x = -Math.PI / 2;
floor.position.y = -6.5;
scene.add(floor);

// Teto
const ceiling = new THREE.Mesh(floorGeometry, new THREE.MeshPhongMaterial({ color: 0xBCBCBC}));
ceiling.position.y = roomHeight - 6.5;
ceiling.rotation.x = Math.PI / 2;
scene.add(ceiling);

// Paredes
const wallGeometry = new THREE.PlaneGeometry(roomWidth, roomHeight);
const backWall = new THREE.Mesh(wallGeometry, roomMaterial);
backWall.position.z = -roomDepth / 2;
backWall.position.y = roomHeight / 2 - 6.5;
backWall.rotation.y = Math.PI; 
scene.add(backWall);

const frontWall = new THREE.Mesh(wallGeometry, roomMaterial);
frontWall.position.z = roomDepth / 2;
frontWall.position.y = roomHeight / 2 - 6.5;
frontWall.rotation.y = Math.PI; 
scene.add(frontWall);

const sideWallGeometry = new THREE.PlaneGeometry(roomDepth, roomHeight);
const leftWall = new THREE.Mesh(sideWallGeometry, roomMaterial);
leftWall.position.x = -roomWidth / 2;
leftWall.position.y = roomHeight / 2 - 6.5;
leftWall.rotation.y = Math.PI / 2 + Math.PI; 
scene.add(leftWall);

const rightWall = new THREE.Mesh(sideWallGeometry, roomMaterial);
rightWall.position.x = roomWidth / 2;
rightWall.position.y = roomHeight / 2 - 6.5;
rightWall.rotation.y = -Math.PI / 2; 
scene.add(rightWall);

// Adicionando TV na frontwall no centro mesmo debaixo dos quadros já la existentes
const tv = createTV({ x: 0, y: -10, z: 0 }, './Texturas/tv.jpg');
frontWall.add(tv);

const graffiti = createGraffiti({ x: 0, y: 2.5, z: 0 }, './Texturas/EASTER.png');
leftWall.add(graffiti);

const imageUrls = [
    './Imagens/meme1.jpg',
    './Imagens/meme2.jpg',
    './Imagens/meme3.jpg',
    './Imagens/meme4.png',
    './Imagens/meme5.png',
    './Imagens/miameme.png',
    './Imagens/meme8.jpg',
    './Imagens/cavalomeme.jpg',
    // Adicione mais URLs conforme necessário
];

const imageUrls2 = [
    './Imagens/meme7.png',
    './Imagens/200.gif',
    './Imagens/yomi-yuumi.png',
    './Imagens/huh-cat-huh-m4rtin.gif',
    
    // Adicione mais URLs conforme necessário
];

// Ajuste as posições dos quadros para que fiquem diretamente acima do sofá
const quadroPositions = [
    { x: 15, y: 10, z: 0 },
    { x: 0, y: 10, z: 0 },
    { x: -15, y: 10, z: 0 },
    { x: -30, y: 10, z: 0 },
    { x: -15, y: -5, z: 0 },
    { x: 15, y: -5, z: 0 },
    { x: 0, y: -5, z: 0 },
    { x: -30, y:-5, z:0 },

];

const quadroPositions2 = [
    { x: 15, y: 10, z: 0 },
    { x: 0, y: 10, z: 0 },
    { x: -15, y: 10, z: 0 },
    { x: -30, y: 10, z: 0 },
    
    // Adicione mais posições conforme necessário
];

const quadroGroup1 = createQuadroGroup(imageUrls, quadroPositions, Math.PI);
const quadroGroup2 = createQuadroGroup(imageUrls2, quadroPositions2, 2 * Math.PI);

addQuadroGroupToWall(backWall, quadroGroup1);
addQuadroGroupToWall(frontWall, quadroGroup2);

// Definindo duas câmeras: uma para visualização dinâmica inicial e uma estática
const dynamicCamera = new THREE.PerspectiveCamera(45, aspect, 0.1, 1000);
dynamicCamera.position.set(0, 20, 30);
dynamicCamera.lookAt(0, 0, 0);

const staticCamera = new THREE.OrthographicCamera(
    frustumSize * aspect / -2,
    frustumSize * aspect / 2,
    frustumSize / 2,
    frustumSize / -2,
    0.1,
    1000
);
staticCamera.position.set(0, 10, 20);
staticCamera.lookAt(0, 3, 0);

let activeCamera = dynamicCamera; // Iniciar com a câmera dinâmica

const renderer = new THREE.WebGLRenderer({ antialias: true });
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

const pointLight = new THREE.PointLight(0xffffff, 1.5, 100);
pointLight.position.set(-30, 20, 25);
scene.add(pointLight);


const candeeiro = createCandeeiro(pointLight,'./Texturas/cadeeiro.jpg');
candeeiro.position.set(-30, 25, 30); // Ajuste a posição do candeeiro
scene.add(candeeiro);


const directionalLight1 = new THREE.DirectionalLight(0xffffff, 0.75);
directionalLight1.position.set(50, 50, 50);
scene.add(directionalLight1);

;

const directionalLight2 = new THREE.DirectionalLight(0xffffff, 0.5);
directionalLight2.position.set(-50, 25, -50);
scene.add(directionalLight2);


const fillLight = new THREE.HemisphereLight(0xffffff, 0x404040, 0.5);
fillLight.position.set(0, 20, 0);
scene.add(fillLight);

const ambientLight = new THREE.AmbientLight(0x404040, 0.3);
scene.add(ambientLight);

const spotLight1 = new THREE.SpotLight(0xffffff, 1.5);
spotLight1.position.set(15, 40, 35);
spotLight1.angle = Math.PI / 6;
spotLight1.penumbra = 0.2;
spotLight1.castShadow = true;
spotLight1.visible = false;  // Initialize as turned off
scene.add(spotLight1);

const spotLight2 = new THREE.SpotLight(0xffffff, 1.5);
spotLight2.position.set(-15, 40, -35);
spotLight2.angle = Math.PI / 6;
spotLight2.penumbra = 0.2;
spotLight2.castShadow = true;
spotLight2.visible = false;  // Initialize as turned off
scene.add(spotLight2);

const BoardTexture = textureLoader.load('./Texturas/tabuleiro.avif')

const boardMaterial = new THREE.MeshPhongMaterial({map: BoardTexture });
const sideBoardGeometry = new THREE.BoxGeometry(0.25, 7, 0.75);
const leftSideBoard = new THREE.Mesh(sideBoardGeometry, boardMaterial);
leftSideBoard.position.set(-3.87, 0.75, 0);
scene.add(leftSideBoard);

const rightSideBoard = new THREE.Mesh(sideBoardGeometry, boardMaterial);
rightSideBoard.position.set(3.87, 0.75, 0);
scene.add(rightSideBoard);

const boardGeometry = new THREE.BoxGeometry(8, 7, 0.25);
const board = new THREE.Mesh(boardGeometry, boardMaterial);
board.position.set(0, 0.75, 0);
scene.add(board);

const holeMaterial = new THREE.MeshBasicMaterial({ color: 0x000000, transparent: true, opacity: 0.5, depthWrite: false });
const holeGeometry = new THREE.CylinderGeometry(0.5, 0.5, 0.3, 32);
const holes = [];
for (let i = -3; i <= 3; i++) {
    for (let j = 0; j < 6; j++) {
        const hole = new THREE.Mesh(holeGeometry, holeMaterial);
        hole.rotation.x = Math.PI / 2;
        hole.position.set(i, j - 2.75, 0);
        board.add(hole);
    }
}

const plataformTexture = textureLoader.load('./Texturas/plataform.jpg');

const platformMaterial = new THREE.MeshPhongMaterial({ map: plataformTexture });
const platform = new THREE.Mesh(new THREE.BoxGeometry(10, 0.5, 14), platformMaterial);
platform.position.set(0, -3, 0);
scene.add(platform);

const tableTexture = textureLoader.load('./Texturas/mesa.png');

const tableMaterial = new THREE.MeshPhongMaterial({ map: tableTexture });
const tableTop = new THREE.Mesh(new THREE.BoxGeometry(12, 0.5, 16), tableMaterial);
tableTop.position.set(0, -3.5, 0);
scene.add(tableTop);

const legGeometry = new THREE.BoxGeometry(0.5, 3, 0.5);
const legPositions = [
    { x: -5.75, z: -7.75 }, { x: 5.75, z: -7.75 }, { x: -5.75, z: 7.75 }, { x: 5.75, z: 7.75 }
];
legPositions.forEach(pos => {
    const leg = new THREE.Mesh(legGeometry, tableMaterial);
    leg.position.set(pos.x, -5.25, pos.z);
    scene.add(leg);
});

const borderMaterial = new THREE.MeshPhongMaterial({ color: 0x222222 });
const borderThickness = 0.25;

const topBorder = new THREE.Mesh(new THREE.BoxGeometry(8.5, borderThickness, 1), borderMaterial);
topBorder.position.set(0, 4.25, 0);
scene.add(topBorder);

const leftBorder = new THREE.Mesh(new THREE.BoxGeometry(borderThickness, 7, 1), borderMaterial);
leftBorder.position.set(-4.25, 0.75, 0);
scene.add(leftBorder);

const rightBorder = new THREE.Mesh(new THREE.BoxGeometry(borderThickness, 7, 1), borderMaterial);
rightBorder.position.set(4.25, 0.75, 0);
scene.add(rightBorder);

const redDiskMaterialTexture = textureLoader.load('./Texturas/reddisks.jpg')
const yellowDiskMaterialTexture = textureLoader.load('./Texturas/yellowdisks.jpg')

const diskGeometry = new THREE.CylinderGeometry(0.5, 0.5, 0.35, 32);
const redDiskMaterial = new THREE.MeshPhongMaterial({ map: redDiskMaterialTexture });
const yellowDiskMaterial = new THREE.MeshPhongMaterial({ map: yellowDiskMaterialTexture });

let currentPlayer = 1;
let highlightDisk;
let eventListenersSet = false;
let columns = [[], [], [], [], [], [], []];
let gameOver = false;
let player1Name = '';
let player2Name = '';
let removeMovementKeybinds = null;

const highlightMaterial = new THREE.MeshBasicMaterial({ color: 0xff0000, transparent: true, opacity: 0.5 });

function createHighlightDisk() {
    const geometry = new THREE.CylinderGeometry(0.5, 0.5, 0.3, 32);
    highlightDisk = new THREE.Mesh(geometry, highlightMaterial);
    highlightDisk.rotation.x = Math.PI / 2;
    highlightDisk.position.set(0, 7, 0);
    scene.add(highlightDisk);
}

function updateHighlightDisk() {
    const color = currentPlayer === 1 ? 0xff0000 : 0xffff00;
    highlightDisk.material.color.setHex(color);
}

createHighlightDisk();

function moveHighlightDisk(position) {
    highlightDisk.position.x = position - 3;
}

function addDisc(columnIndex) {
    if (gameOver) return;
    if (columns[columnIndex].length < 6) {
        const row = columns[columnIndex].length;
        const color = currentPlayer === 1 ? 0xff0000 : 0xffff00;
        const material = currentPlayer === 1 ? redDiskMaterial : yellowDiskMaterial;
        const disk = new THREE.Mesh(diskGeometry, material);
        disk.rotation.x = Math.PI / 2;
        disk.position.set(columnIndex - 3, 7, 0);
        scene.add(disk);
        const targetY = row - 2.75 + 0.75;
        animateDisk(disk, targetY, columnIndex, row, currentPlayer);
        columns[columnIndex].push({ disk, player: currentPlayer });
        currentPlayer = currentPlayer === 1 ? 2 : 1;
        updateHighlightDisk();
    }
}

function animateDisk(disk, targetY, columnIndex, row, player) {
    new TWEEN.Tween(disk.position)
        .to({ y: targetY }, 1000)
        .easing(TWEEN.Easing.Bounce.Out)
        .onComplete(() => {
            if (checkWin(columnIndex, row, player)) {
                setTimeout(() => {
                    announceWinner(player);
                }, 500);
            } else if (checkDraw()) {
                setTimeout(() => {
                    showWinnerMessage('Empate!');
                    resetGame();
                }, 500);
            }
        })
        .start();
}

function checkWin(columnIndex, rowIndex, player) {
    const directions = [
        { x: 1, y: 0 }, { x: 0, y: 1 }, { x: 1, y: 1 }, { x: 1, y: -1 }
    ];

    for (let { x, y } of directions) {
        let count = 1;

        for (let dir = -1; dir <= 1; dir += 2) {
            let col = columnIndex + dir * x;
            let row = rowIndex + dir * y;
            while (col >= 0 && col < 7 && row >= 0 && row < 6 && columns[col][row] && columns[col][row].player === player) {
                count++;
                col += dir * x;
                row += dir * y;
            }
        }

        if (count >= 4) {
            return true;
        }
    }
    return false;
}

function checkDraw() {
    return columns.every(column => column.length === 6);
}

function showWinnerMessage(message) {
    const winnerTextElement = document.getElementById('winnerText');
    winnerTextElement.textContent = message;
    
    const winnerMessageElement = document.getElementById('winnerMessage');
    winnerMessageElement.style.display = 'block';

    const victoryImage = document.getElementById('victoryImage');
    victoryImage.style.display = 'block';
}


function announceWinner(player) {
    gameOver = true;

    // Parar a música de fundo
    const backgroundMusic = document.getElementById('backgroundMusic');
    backgroundMusic.pause();

    // Tocar o som de vitória
    const victorySound = document.getElementById('victorySound');
    victorySound.play();

    confetti({
        particleCount: 200,
        spread: 70,
        origin: { y: 0.6 }
    });

    const winnerMessage = `Parabéns ${player === 1 ? player1Name : player2Name} foste abençoado por D.Zeca!`;
    showWinnerMessage(winnerMessage);
}


function resetGame() {
    gameOver = false;
    columns.forEach(column => column.forEach(diskObj => scene.remove(diskObj.disk)));
    columns = [[], [], [], [], [], [], []];
    currentPlayer = 1;
    scene.remove(highlightDisk);
    createHighlightDisk();
    updateHighlightDisk();
    const winnerMessageElement = document.getElementById('winnerMessage');
    winnerMessageElement.style.display = 'none';

    // Parar a música de vitória
    const victorySound = document.getElementById('victorySound');
    victorySound.pause();
    victorySound.currentTime = 0; // Reiniciar o som de vitória

    // Se houver movimento de keybinds configurado, remova-o
    if (removeMovementKeybinds) removeMovementKeybinds();
    removeMovementKeybinds = setupMovementKeybinds(highlightDisk, addDisc, () => gameOver);

    const backgroundMusic = document.getElementById('backgroundMusic');
    backgroundMusic.play();
}

function showMenu() {
    document.getElementById('menu').style.display = 'block';
    document.getElementById('startGameButton').style.display = gameOver ? 'block' : 'none';
    document.getElementById('resetGameButton').style.display = gameOver ? 'none' : 'block';
}

function hideMenu() {
    document.getElementById('menu').style.display = 'none';
}

// Configurar keybinds para iluminação
setupLightKeybinds(pointLight, directionalLight1, directionalLight2, fillLight, ambientLight, spotLight1, spotLight2);

// Configurar keybinds para menu
setupMenuKeybinds(showMenu);


// Criação dos controles da câmera
const controls = new OrbitControls(dynamicCamera, renderer.domElement);
controls.maxPolarAngle = Math.PI / 2;
controls.minDistance = 10;
controls.maxDistance = 50;

// Keybind to switch cameras
document.addEventListener('keydown', event => {
    if (event.key === 'c') {
        activeCamera = (activeCamera === dynamicCamera) ? staticCamera : dynamicCamera;
    }
});

function animate() {
    requestAnimationFrame(animate);
    TWEEN.update();
    controls.update();
    renderer.render(scene, activeCamera);
}

animate();

window.addEventListener('resize', () => {
    const aspect = window.innerWidth / window.innerHeight;
    dynamicCamera.aspect = aspect;
    dynamicCamera.updateProjectionMatrix();
    staticCamera.left = frustumSize * aspect / -2;
    staticCamera.right = frustumSize * aspect / 2;
    staticCamera.top = frustumSize / 2;
    staticCamera.bottom = frustumSize / -2;
    staticCamera.updateProjectionMatrix();
    renderer.setSize(window.innerWidth, window.innerHeight);
});




// Menu logic
// Menu logic

document.addEventListener('DOMContentLoaded', () => {
    const loadingScreen = document.getElementById('loadingScreen');
    const welcomeScreen = document.getElementById('welcomeScreen');
    const enterGameButton = document.getElementById('enterGameButton');
    const menuMusic = document.getElementById('menuMusic');

    // Função para exibir a tela de carregamento com as dicas
    function showLoadingScreen() {
        const tipElement = document.getElementById('tip');
        tipElement.innerHTML = getDicaAleatoria().replace(/\n/g, '<br>');
        loadingScreen.style.display = 'flex';

        setTimeout(() => {
            loadingScreen.style.display = 'none';
            document.getElementById('menu').style.display = 'block';
            menuMusic.play();
        }, 4000); // Duração da tela de carregamento
    }

    // Iniciar a música do menu após a interação do usuário
    enterGameButton.addEventListener('click', () => {
        welcomeScreen.style.display = 'none';
        showLoadingScreen();
    });
});

document.getElementById('startGameButton').addEventListener('click', () => {
    document.getElementById('nameInputContainer').style.display = 'block';
    document.getElementById('menu').style.display = 'none';
    const menuMusic = document.getElementById('menuMusic');
    menuMusic.pause();
});

document.getElementById('startButton').addEventListener('click', () => {
    player1Name = document.getElementById('player1NameInput').value;
    player2Name = document.getElementById('player2NameInput').value;
    document.getElementById('nameInputContainer').style.display = 'none';
    hideMenu();
    resetGame();
    const backgroundMusic = document.getElementById('backgroundMusic');
    backgroundMusic.play();
    backgroundMusic.volume = 0.5; // Ajustar o volume se necessário
});

document.getElementById('cancelButton').addEventListener('click', () => {
    document.getElementById('nameInputContainer').style.display = 'none';
    document.getElementById('menu').style.display = 'block';
    const menuMusic = document.getElementById('menuMusic');
    menuMusic.play();
});

document.getElementById('resetGameButton').addEventListener('click', () => {
    resetGame();
    hideMenu();
    const menuMusic = document.getElementById('menuMusic');
    menuMusic.pause();
});

document.getElementById('exitButton').addEventListener('click', () => {
    window.close();
});

document.getElementById('returnToMenuButton').addEventListener('click', () => {
    document.getElementById('winnerMessage').style.display = 'none';
    document.getElementById('victoryImage').style.display = 'none';
    showMenu();

    // Parar a música de vitória
    const victorySound = document.getElementById('victorySound');
    victorySound.pause();
    victorySound.currentTime = 0; 

    // Tocar a música do menu
    const menuMusic = document.getElementById('menuMusic');
    menuMusic.play();
});



document.getElementById('showManualButton').addEventListener('click', () => {
    document.getElementById('manual').style.display = 'block';
});

document.getElementById('closeManualButton').addEventListener('click', () => {
    document.getElementById('manual').style.display = 'none';
});









